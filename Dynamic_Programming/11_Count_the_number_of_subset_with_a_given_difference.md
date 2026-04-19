- Array ko 2 subset me todna hai, let's say s1 and s2 with a given difference -- diff
- How many pairs of such subsets can we form?
- s1 - s2 = diff
- s1 + s2 = sum(arr)
- 2s1 = diff + sum(arr)
- s1 = (diff + sum(arr))/2

- We have reduced this to a Q of finding the number of subsets with a given sum

- Jab bhi koi naya problem dikhe to socho ki kya maine isse similar problem banaya hai. Then do some variation and you will get the required code.