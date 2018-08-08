//https://www.cnblogs.com/yjiyjige/p/3263858.html
// https://blog.csdn.net/gesanghuazgy/article/details/52214718
// https://www.cnblogs.com/c-cloud/p/3224788.html
// http://blog.51cto.com/13577765/2064490

// //next的求解
// private static void getNext(int[] next, String str) {
//         next[0]=-1;//初始化
//         int k=-1;//记录当前位的next
//         int j=0;//当前位下标
//         while(j<str.length()-1){//求解完所有字符的next
//             if(k==-1||str.charAt(j)==str.charAt(k)){//比较当前位与当前位next字符是否相等
//                 j++;
//                 k++;//当前位的next值+1作为下一位的next值
//                 next[j]=k;//求解出下一位的next值
//             }else{
//                 k=next[k];//如果不相等则找当前位的next的next与当前位比较
//             }
//         }
//     }

