class Score {

    protected:
        int score;

    public:
        Score()
        : score{0}
        {}

        Score& operator++() {
            score++;
            return *this;
        }

        Score& operator+=(int n) {
            score+=n;
            return *this;
        }
};
