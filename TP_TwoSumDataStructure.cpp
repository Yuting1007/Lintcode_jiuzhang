class TwoSum{
public:
    void add(int number){
        ++table[number];
    }

    bool find(int value){
        //use iterator
        for(auto it = table.begin(); it != table.end(); ++it){
            int a = it->first;
            int b = value - a;

            if((a != b && table.count(b)) || (a = b && it->second > 1)){
                return true;
            }
        }
        return false;
    }

private:
//<number, frequency>
    unordered_map<int, int> table;
};
