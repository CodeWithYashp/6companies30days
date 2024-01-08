class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secretfreq;
        unordered_map<char, int> guessfreq;
        int m = secret.size();
        int bull = 0;
        int cow = 0;

        for(int i = 0 ; i < m; i++){
                if(secret[i] == guess[i]){
                    bull++;
                }else{
                    secretfreq[secret[i]]++;
                    guessfreq[guess[i]]++;
                }
            
        }
        for (auto& pair : secretfreq) {
            cow += min(guessfreq[pair.first], pair.second);
        }

        cout<<bull<<" "<<cow<<endl;
        return to_string(bull) + 'A'+ to_string(cow)+ 'B';
    }
};