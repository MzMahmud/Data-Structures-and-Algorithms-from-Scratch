class DisjointSet<TKey> {
    private parents = new Map<TKey, TKey>();
    private ranks = new Map<TKey, number>();
    private nComponents = 0;

    constructor(data?: Iterable<TKey>) {
        if (data != null) for (const key of data) this.add(key);
    }

    find(key: TKey): TKey | undefined {
        let parent = this.parents.get(key);
        if (parent == null) return undefined;
        if (parent === key) return key;
        parent = this.find(parent);
        if (parent == undefined) return undefined;
        this.parents.set(key, parent);
        return parent;
    }

    union(a: TKey, b: TKey): boolean {
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

    isInSameSet(a: TKey, b: TKey): boolean {
        return this.find(a) === this.find(b);
    }

    get size(): number {
        return this.nComponents;
    }

    add(key: TKey): boolean {
        if (this.parents.has(key)) return false;
        this.nComponents++;
        this.parents.set(key, key);
        this.ranks.set(key, 1);
        return true;
    }

    getDisjointSets() {
        const sets = new Map<TKey, TKey[]>();
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
