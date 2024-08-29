class DisjointSet<T> {
    private parents = new Map<T, T>();
    private ranks = new Map<T, number>();
    private nComponents = 0;

    constructor(data?: Iterable<T>) {
        if (data != null) for (const key of data) this.add(key);
    }

    find(t: T): T | undefined {
        let parent = this.parents.get(t);
        if (parent == null) return undefined;
        if (parent === t) return t;
        parent = this.find(parent);
        if (parent == undefined) return undefined;
        this.parents.set(t, parent);
        return parent;
    }

    union(a: T, b: T): boolean {
        const parA = this.find(a), parB = this.find(b);
        if (parA == undefined || parB == undefined) return false;
        if (parA === parB) return false;
        this.nComponents--;
        const rankA = this.ranks.get(parA) ?? 0;
        const rankB = this.ranks.get(parB) ?? 0;
        const totalRank = rankA + rankB;
        if (rankA > rankB) {
            this.parents.set(parB, parA);
            this.ranks.set(parA, totalRank);
        } else {
            this.parents.set(parA, parB);
            this.ranks.set(parB, totalRank);
        }
        return true;
    }

    isInSameSet(a: T, b: T): boolean {
        return this.find(a) === this.find(b);
    }

    get size(): number {
        return this.nComponents;
    }

    add(t: T): boolean {
        if (this.parents.has(t)) return false;
        this.nComponents++;
        this.parents.set(t, t);
        this.ranks.set(t, 1);
        return true;
    }

    getDisjointSets() {
        const sets = new Map<T, T[]>();
        for (const key of this.parents.keys()) {
            const parent = this.find(key);
            if (parent == undefined) continue;
            if (!sets.has(parent)) sets.set(parent, []);
            sets.get(parent)!.push(key);
        }
        return [...sets.values()];
    }
}

const ds = new DisjointSet<number>([1, 2, 3, 4, 5, 6, 4, 7, 1, 2, 1]);
ds.union(1, 2);
ds.union(4, 5);
ds.union(5, 6);
ds.union(1, 6);
ds.union(2, 6);
ds.add(10);
ds.add(9);
console.log(ds.getDisjointSets(), ds.size);
console.log(ds.isInSameSet(5, 3));
console.log(ds.isInSameSet(4, 1));
