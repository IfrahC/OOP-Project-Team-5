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

 Cell& Cell::operator=(const Cell& c) const {
    x = c.x;
    y = c.y;
    visited = c.visited;
    eastwalls=c.eastwalls;
    westwalls=c.westwalls;
    northwalls=c.northwalls;
    southwalls=c.southwalls;

    return *this;
}

std::string Cell::direction(const Cell& other) {
    if (x == other.x && y + 1 == other.y)
        return "E";
    if (x == other.x && y - 1 == other.y)
        return "W";
    if (x - 1 == other.x && y == other.y)
        return "N";
    if (x + 1 == other.x && y == other.y)
        return "S";
    return "";
}
std::string Cell::directionopposite(std::string direct) {
    if (direct=="W")
        {return "E";}
    else if (direct=="E")
        {return "W";}
    else if (direct=="S")
        {return "N";}
    else if (direct=="N")
        {return "S";}
    return "";
}
