class Collectables {
    private:
        int score;
    public:
        virtual int incrementScore(int score);
};

class Coins : public Collectables {
    public:
        int incrementScore(int score) override {
            score+=1;
        }
};

class Diamonds : public Collectables {
    public:
        int incrementScore(int score) override {
            score+=5;
        }
};
