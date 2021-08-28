/*

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
unordered_map<pair<int, int>, bool, hash_pair> um;

-------------------------------------------------------------------------------------------

rounding up
ceil is SIF smallest integer greater than given float;
ceil(a/b)=(a+b-1)/b;
rounding down
floor is GIF greatest integer smaller than given float;
floor(a/b)=ceil(a/b)-1=((a+b-1)/b)-1;

-------------------------------------------------------------------------------------------

lower_bound points to first element greater than or equal to val.
upper_bound points to first element greater than val
usage
lower = lower_bound (v.begin(), v.end(), val);  
upper = upper_bound (v.begin(), v.end(), val);  

lower_bound and upper_bound can be used to find the lesser or equal and lesser(respectively) to val also...
sort(rall(v));
lower=lower_bound(all(v),val,greater<int>());
upper=upper_bound(all(v),val,greater<int>());

-------------------------------------------------------------------------------------------

replace function with strings...
s1=string in which replacement has to be made;
s2=string that replaces;
start=index where replacement would began;
span=how many indexes it would cover;
usage
s1.replace(start,span,s2);

--------------------------------------------------------------------------------------------
syntax for priority queue in cpp
max heap(largest on top)
priority_queue<int> one;

min heap(smallest on top)
priority_queue<int,vector<int>,greater<int>> two;

*/
