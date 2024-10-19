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
string Add(string str1, string str2);


string Mul(string str1, string str2){
    if(CheckZero(str1)||CheckZero(str2)) return "0";    //如果有一个为0,则结果为0
 
    int negative=0,negastr1=0,negastr2=0;               //定正负
    if(CheckNegative(str1)){                            //确定正负号标记，并且去掉-字符
        negastr1=1; str1=str1.substr(1,str1.size()-1);
    }
    if(CheckNegative(str2)){
        negastr2=1; str2=str2.substr(1,str2.size()-1);
    }
    negative=negastr1^negastr2;                         //异或运算确定结果的正负号
 
    string ans;
    if(Lower(str1,str2)) swap(str1,str2);               //保证str1大于等于str2
    int size1=str1.size(),size2=str2.size();
    for(int i=size2-1;i>=0;i--){                        //遍历较小数字的每一位
        string temp(size2-1-i,'0');                     //temp为str1乘以str2[i]的积，根据str2[i]的权重（个十百千万，补充对应个数的0）
        int flag=0;                                     //进位标记
        for(int j=size1-1;j>=0;j--){                    //temp
            flag+=(str1[j]-'0')*(str2[i]-'0');
            temp.push_back('0'+(flag%10));
            flag/=10;
        }
        if(flag) temp.push_back('0'+flag);              //如果最高位还有进位
        reverse(temp.begin(),temp.end());
        ans=Add(ans,temp);                              //将计算结果累加到最终的结果上
    }
    if(negative) ans="-"+ans;                           //处理结果的正负号
    return ans;
}



string Add(string str1, string str2){
    //关于0的处理
    if(CheckZero(str1)&&CheckZero(str2)) return "0";    //如果都是0
    else if(CheckZero(str1)) return str2;               //如果有个一为0
    else if(CheckZero(str2)) return str1;
    string ans;
    int i=str1.size()-1,j=str2.size()-1;
    int flag=0;                                         //进位标记
    while(i>=0||j>=0||flag){
        int numa=i>=0?str1[i--]-'0':0;                  //如果所有位都访问完毕，对应的位置用0代替
        int numb=j>=0?str2[j--]-'0':0;
        flag=numa+numb+flag;                            //计算两位的和
        ans+='0'+flag%10;                               //取个位保存在答案中
        flag/=10;                                       //计算进位
    }
    reverse(ans.begin(),ans.end());
    return ans;
}