class Stream<T>{
    constructor(private stream: Generator<T, void, unknown>) { }

    static fromIterable<T>(iterable: Iterable<T>) {
        const stream = (function* () {
            for (const t of iterable) {
                yield t;
            }
        })();
        return new Stream(stream);
    }

    static create<T>(...ts: T[]) {
        return Stream.fromIterable(ts);
    }

    map<R>(mapFn: (t: T) => R) {
        const stream = this.stream;
        const mapped = (function* () {
            for (const t of stream) {
                yield mapFn(t)
            }
        })();
        return new Stream(mapped);
    }

    filter(filterFn: (t: T) => boolean) {
        const stream = this.stream;
        const mapped = (function* () {
            for (const t of stream) {
                if (filterFn(t)) {
                    yield t;
                }
            }
        })();
        return new Stream(mapped);
    }

    forEach(consumer: (t: T) => void) {
        for (const t of this.stream) {
            consumer(t);
        }
    }

    reduce<R>(reducerFn: (r: R, t: T) => R, identity: R) {
        let reduced = identity;
        for (const t of this.stream) {
            reduced = reducerFn(reduced, t);
        }
        return reduced;
    }

    sum() {
        let s = 0;
        for (const t of this.stream) {
            s += t as number;
        }
        return s;
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
}
