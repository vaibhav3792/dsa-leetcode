## Code

```cpp

string temp = to_string(i);
temp.push_back(' ');
temp.append(to_string(j));
temp.push_back(' ');
temp.append(to_string(isTrue));
if(mp.find(temp)!=mp.end()){
    return mp[temp];
}
.
.
.
.
return mp[temp] = ans;

```