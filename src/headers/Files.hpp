namespace drk
{
    //should be open as long as settings screen is open
    class GameData
    {
    public:
        //opens file
        GameData(/* args */);
        //closes file and saves changes
        ~GameData();
    private:
        bool is_36_card_deck;
        unsigned short colour_scheme;
    }; 
}