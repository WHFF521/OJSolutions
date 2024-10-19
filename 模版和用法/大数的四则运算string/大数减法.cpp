#include<string>
using namespace std;

bool CheckZero(const string &str){      //检查是否等于0
    int size=str.size();                //如果全是0则为0，这里假设不会有带符号的+00000或者-00000作为输入
    for(int i=0;i<size;i++)
        if(str[i]!='0') return false;
    return true;
}

bool Lower(string str1, string str2){                   //长度长的一定大（这里假设除了0以外，都没有前导0），长度相等则字典序小的数字更小
    return str1.size()<str2.size()||(str1.size()==str2.size()&&str1<str2);
}

string Sub(string str1, string str2){
    //处理0的情况
    if(str1==str2||(CheckZero(str1)&&CheckZero(str2))) return "0";  //如果两数相等或者都是0
    else if(CheckZero(str1)) return "-"+str2;                       //如果第一个数字为0
    else if(CheckZero(str2)) return str1;                           //如果第二个数字为0
    //定正负
    int negative=0;                     //结果的正负号
    if(Lower(str1,str2)){
        swap(str1,str2);                //保证str1大于str2
        negative=1;                     //如果str1小于str2，则结果过为负值
    }
    string ans;
    int i=str1.size()-1,j=str2.size()-1;//逆序开始处理
    int flag=0;                         //借位标记
    while(i>=0||j>=0){
        int numa=i>=0?str1[i--]-'0':0;  //取每一位，因为长度可能不同所以当某一个已经读取完毕时对应位置取0
        int numb=j>=0?str2[j--]-'0':0;
        numa-=flag;                     //先减去借位
        if(numa<numb){                  //如果不够减则向上一位借位（只可能借一位）
            numa+=10;                   //借位并记录借位
            flag=1;
        }
        else flag=0;                    //如果不借位，则借位标记为0
        ans+='0'+numa-numb;             //计算当前位置并保存
    }
    i=ans.size()-1;
    while(ans[i]=='0') i--;
    ans=ans.substr(0,i+1);              //去除前导0,如111-110=1
    if(negative) ans+='-';              //如果计算结果是负数，添加负数符号
    reverse(ans.begin(),ans.end());     //因为是逆序计算得到的结果，所以需要翻转一下
    return ans;
}
