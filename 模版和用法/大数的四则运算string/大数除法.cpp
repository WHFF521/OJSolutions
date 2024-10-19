// # 商业转载请联系作者获得授权，非商业转载请注明出处。
// # For commercial use, please contact the author for authorization. For non-commercial use, please indicate the source.
// # 协议(License)：署名-非商业性使用-相同方式共享 4.0 国际 (CC BY-NC-SA 4.0)
// # 作者(Author)：songjiahao
// # 链接(URL)：https://blog.songjiahao.com/archives/382
// # 来源(Source)：SAquariusの梦想屋
#include<string>
using namespace std;
bool CheckZero(const string &str){      //检查是否等于0
    int size=str.size();                //如果全是0则为0，这里假设不会有带符号的+00000或者-00000作为输入
    for(int i=0;i<size;i++)
        if(str[i]!='0') return false;
    return true;
}

bool CheckNegative(const string &str){  //检查是否为负数
    return str[0]=='-';
}
bool Lower(string str1, string str2){                   //长度长的一定大（这里假设除了0以外，都没有前导0），长度相等则字典序小的数字更小
    return str1.size()<str2.size()||(str1.size()==str2.size()&&str1<str2);
}
string Sub(string str1, string str2);

string Div(string str1, string str2){
    //处理除数为0的情况和被除数为0的情况
    if(CheckZero(str2)) return "The divisor cannot be zero!";
    else if(CheckZero(str1)) return "0.000000";
 
    int negative=0,negastr1=0,negastr2=0;               //定正负
    if(CheckNegative(str1)){                            //确定正负号标记，并且去掉-
        negastr1=1; str1=str1.substr(1,str1.size()-1);
    }
    if(CheckNegative(str2)){
        negastr2=1; str2=str2.substr(1,str2.size()-1);
    }
    negative=negastr1^negastr2;                         //异或运算确定结果的正负号
 
    int point=0;                                        //结果是否为纯小数
    if(Lower(str1,str2)) point=1;                       //如果str1小于str2，则计算为纯小数
    string ans;                                         //计算结果
    str1+=string(6,'0');                                //补足6个0，用于计算小数位
 
    int size1=str1.size(),size2=str2.size();
    int i=size2-1;                                      //商第一位的位置
    string temp=str1.substr(0,i);                       //从str1上取size2-1个字符
    for(i;i<size1;i++){
        temp+=str1[i];                                  //从后边拿出一位，预先处理可以防止结尾处越界
        int cnt=0;                                      //当前位的商，也就是temp中包含了多少个str2，使用减法                                          //如果temp不为0，则计算商
        while(Lower(str2,temp)||temp==str2){            //如果当前位商不为0，则计算商
            temp=Sub(temp,str2);
            cnt++;
        }
        if(temp=="0") temp.clear();                     //如果某次计算结果为0，则清空，避免0的堆积,比如111000 111
        ans.push_back('0'+cnt);                         //保存商
    }
    i=0;
    while(ans[i]=='0') i++;
    ans=ans.substr(i,ans.size()-i);                     //去除前导0
    if(point){                                          //如果是纯小数,补足6位并添加小数点
        int len=6-ans.size();
        ans="0."+string(len,'0')+ans;
    }
    else ans.insert((ans.end()-6),'.');                 //如果不是小数，则只需要插入小数点       
    if(negative) ans="-"+ans;                           //最后一步骤，如果是负数带上负号
    return ans;
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
