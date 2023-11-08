class Cell {
    public:
    Cell() = default;
    Cell(int i, int j);
    bool eastwalls;
    bool westwalls;
    bool northwalls;
    bool southwalls;
    int x;
    int y;
    bool visited;
};
Cell::Cell(int i, int j)
    : x(i), y(j), visited(false) {
    eastwalls=true;
    westwalls=true;
    northwalls=true;
    southwalls=true;}
