#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

int main(){
    int b, p;
    cin >> b >> p;

    vector<ll> bar(b), plate(p), valid, ans;
    for(int i = 0 ; i < b ; i++){
        cin >> bar[i];
    }   
    for(int i = 0 ; i < p ; i++){
        cin >> plate[i];
    }

    sort(bar.begin(), bar.end());
    sort(plate.begin(), plate.end());

    for(int i = 0 ; i < pow(2, plate.size()) ; i++){
        int bit = i;
        ll weight = 0;
        vector<int> bm;
        for(int j = 0 ; j < plate.size() ; j++){
            if(bit % 2){
                weight += plate[j];
            }
            else{
                bm.push_back(plate[j]);
            }
            bit /= 2;
        }

        for(int j = 0 ; j < pow(2, bm.size()) ; j++){
            int bit2 = j;
            ll weight2 = 0;
            for(int k = 0 ; k < bm.size() ; k++){
                if(bit2 % 2){
                    weight2 += bm[k];
                }
                bit2 /= 2;
            }
            if(weight == weight2){
                valid.push_back(weight);
            }
        }
    }

    sort(valid.begin(), valid.end());
    valid.erase(unique(valid.begin(), valid.end()), valid.end());
    for(int i = 0 ; i < valid.size() ; i++){
        for(int j = 0 ; j < bar.size() ; j++){
            ans.push_back(valid[i] * 2 + bar[j]);
        }   
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << "\n";
    }

}