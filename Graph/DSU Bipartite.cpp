class DSU {
   public:
    DSU(size_t n)
        : parent_(n, -1), len_(n, 0) {
    }

    std::pair<int, int> Find(int x) {
        if (parent_[x] < 0) {
            return {x, 0};
        }
        const auto [p, l] = Find(parent_[x]);
        parent_[x] = p;
        len_[x] = (len_[x] + l) % 2;
        return {p, len_[x]};
    }

    bool Union(int x, int y) {
        auto [px, lx] = Find(x);
        auto [py, ly] = Find(y);
        if (px == py) {
            return lx != ly;
        }
        if (parent_[px] > parent_[py]) {
            std::swap(px, py);
            std::swap(lx, ly);
        }
        parent_[px] += parent_[py];
        parent_[py] = px;
        len_[py] = (1 + lx + ly) % 2;
        return true;
    }
   private:
    std::vector<int> parent_, len_;
};
