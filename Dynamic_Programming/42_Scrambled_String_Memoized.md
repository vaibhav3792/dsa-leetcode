## Code

```cpp
unordered_map<string,bool> mp;
string key = a;
key.push_back(' ');
key.append(b);
if(mp.find(key)!=mp.end()){
    return mp[key];
}
.
.
.
return mp[key] = flag;

```