#include <bits/stdc++.h>

using namespace std;

// array of longest increasing subseq
vector<int> LIS (vector<int>& v) {
    if (v.size() == 0) {
      return {};
    }
    
    vector<int> p(v.size(), -1);
    vector<int> t(v.size(), 0);

    int lis = 1;
    for(int i = 1; i < v.size(); i++) {
        if (v[i] <= v[t[0]]) {
            t[0] = i;
        }
        else if(v[i] > v[t[lis - 1]]) {
            p[i] = t[lis - 1];
            t[lis++] = i;
        }
        else {
            int l = -1;
            int r = lis - 1;
            while(r - l > 1) {
                int m = l + (r - l) / 2;
                if(v[t[m]] >= v[i]) r = m;
                else l = m;
            }
            p[i] = t[r - 1];
            t[r] = i;
        }
    }

    vector<int> ans;
    for (int i = t[lis - 1]; i >= 0; i = p[i]) {
        ans.push_back(i);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> signals(n);

    for (int i=0; i < n; i++) {
      cin >> signals[i];
    }


    cout << LIS(signals).size() << endl;













    return 0;
}
