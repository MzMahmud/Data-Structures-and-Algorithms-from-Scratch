class Stream<T> {
    constructor(private stream: Generator<T, void, unknown>) { }

    static fromGenerator<T>(generator: Generator<T, void, unknown>) {
        return new Stream(generator);
    }

    static fromIterable<T>(iterable: Iterable<T>) {
        const stream = (function* () {
            for (const t of iterable) yield t;
        })();
        return new Stream(stream);
    }

    static create<T>(...ts: T[]) {
        return Stream.fromIterable(ts);
    }

    static iterate<T>(
        initialValue: T,
        iterationCondition: (t: T, index: number) => boolean,
        nextValue: (prevValue: T, index: number) => T
    ) {
        const stream = (function* () {
            let i = 0;
            for (let t = initialValue; iterationCondition(t, i); t = nextValue(t, i)) {
                yield t;
                i++;
            }
        })();
        return new Stream(stream);
    }

    static iterateWithIndex<T>(
        initialValue: T,
        iterationCondition: (t: T, index: number) => boolean,
        nextValue: (prevValue: T, index: number) => T
    ) {
        return Stream.iterate(
            [0, initialValue] as readonly [number, T],
            ([_, t], i) => iterationCondition(t, i),
            ([_, t], i) => [i, nextValue(t, i)] as readonly [number, T]
        );
    }

    static iterateInfinite<T>(initialValue: T, nextValue: (prevValue: T, index: number) => T) {
        return Stream.iterate(initialValue, () => true, nextValue);
    }

    static iterateInfiniteWithIndex<T>(initialValue: T, nextValue: (prevValue: T, index: number) => T) {
        return Stream.iterateWithIndex(initialValue, () => true, nextValue);
    }

    static concat<T>(...streams: Stream<T>[]) {
        const concated = (function* () {
            for (const { stream } of streams) {
                for (let it = stream.next(); !it.done; it = stream.next()) {
                    yield it.value;
                }
            }
        })();
        return new Stream(concated);
    }

    static concatIterable<T>(...itarables: Iterable<T>[]) {
        const streams = itarables.map(it => Stream.fromIterable(it));
        return Stream.concat(...streams);
    }

    map<R>(mapFn: (t: T) => R) {
        const stream = this.stream;
        const mapped = (function* () {
            for (let it = stream.next(); !it.done; it = stream.next()) {
                const t = it.value;
                yield mapFn(t);
            }
        })();
        return new Stream(mapped);
    }

    peek(consumer: (t: T) => void) {
        return this.map((t) => {
            consumer(t);
            return t;
        })
    }

    filter(filterFn: (t: T) => boolean) {
        const stream = this.stream;
        const filtered = (function* () {
            for (let it = stream.next(); !it.done; it = stream.next()) {
                const t = it.value;
                if (filterFn(t)) {
                    yield t;
                }
            }
        })();
        return new Stream(filtered);
    }

    takeWhile(predicate: (t: T) => boolean) {
        const stream = this.stream;
        const taken = (function* () {
            for (let it = stream.next(); !it.done && predicate(it.value); it = stream.next()) {
                yield it.value;
            }
        })();
        return new Stream(taken);
    }

    take(n: number) {
        const count = [0];
        const predicate = () => count[0]++ < n;
        return this.takeWhile(predicate);
    }

    append(stream: Stream<T>) {
        return Stream.concat(this, stream);
    }

    appendIterable(itarable: Iterable<T>) {
        return Stream.concat(this, Stream.fromIterable(itarable));
    }

    prepend(stream: Stream<T>) {
        return Stream.concat(stream, this);
    }

    prependIterable(itarable: Iterable<T>) {
        return Stream.concat(Stream.fromIterable(itarable), this);
    }

    forEach(consumer: (t: T) => void) {
        for (let it = this.stream.next(); !it.done; it = this.stream.next()) {
            const t = it.value;
            consumer(t);
        }
    }

    reduce<R>(reducerFn: (r: R, t: T) => R, identity: R) {
        let reduced = identity;
        for (let it = this.stream.next(); !it.done; it = this.stream.next()) {
            const t = it.value;
            reduced = reducerFn(reduced, t);
        }
        return reduced;
    }

    sum() {
        return this.reduce((s, t) => s + (t as number), 0);
    }

    toArray() {
        return [...this.stream];
    }

    toSet() {
        return this.reduce(
            (s, t) => {
                s.add(t);
                return s
            },
            new Set<T>()
        );
    }

    allMatch(predicate: (t: T) => boolean) {
        for (let it = this.stream.next(); !it.done; it = this.stream.next()) {
            if (!predicate(it.value)) {
                return false;
            }
        }
        return true;
    }

    anyMatch(predicate: (t: T) => boolean) {
        for (let it = this.stream.next(); !it.done; it = this.stream.next()) {
            if (predicate(it.value)) {
                return true;
            }
        }
        return false;
    }

    noneMatch(predicate: (t: T) => boolean) {
        return !this.anyMatch(predicate);
    }

    groupBy<K, V>(keyMapper: (t: T) => K, valueMapper: (t: T) => V) {
        return this.reduce(
            (map, t) => {
                const key = keyMapper(t);
                if (!map.has(key)) map.set(key, []);
                map.get(key)?.push(valueMapper(t));
                return map;
            },
            new Map<K, V[]>()
        );
    }

    max(compareFn?: (a: T, b: T) => number) {
        if (compareFn == null) compareFn = (a, b) => a === b ? 0 : a < b ? -1 : 1;
        return this.reduce(
            (max, t) => (max === null || compareFn(t, max) > 0) ? t : max,
            null as T | null
        );
    }

    min(compareFn?: (a: T, b: T) => number) {
        if (compareFn == null) compareFn = (a, b) => a === b ? 0 : a < b ? -1 : 1;
        return this.reduce(
            (min, t) => (min === null || compareFn(t, min) < 0) ? t : min,
            null as T | null
        );
    }
}
