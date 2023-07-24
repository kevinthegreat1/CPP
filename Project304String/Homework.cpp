/*
 * Q1:
 *      给定字符串S(length<1E6)，它是由另一个字符串X重复若干次得到的，至少两次，次数可能不是整数，问X最短是多长？
 *      S=cabcabcabcab
 *      X=cab
 * 
 * Q2:
 *      给定字符串S，如果对于S的长度为i的前缀是“循环同构”的（由某个字符串X重复至少两次得到），求i和重复次数c
 *      S=aaa
 *      i=[2,3]
 *      c=[2,3]
 * 
 *      S=aabaabaabaab
 *      i=[2,6,9,12]
 *      c=[2,2,3,4]
 * 
 * Q3:
 *      给定一个字符串S，如果S的一个不等于S的前缀X满足：S是X+X的前缀，就把X叫做S的一个“周期串”，求所有前缀的最大周期串长度之和
 *      S=babababa
 *      prefix: b: none
 *              ba: none
 *              bab: ba 2
 *              baba: ba 2
 *              babab: baba 4
 *              bababa: baba 4
 *              bababab: baba, bababa, max(4,6)=6
 *              babababa: baba, bababa, max(4,6)=6
 *      ans=24
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */