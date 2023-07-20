#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    // the 2 numbers need to be added together can't read as int,
    // the 3,4 test case will fail
    // after I read them as char array, the code can work properly
    // Guess maybe there is something wrong about the "scanf" function
    // Should learn more about c and c++
    int standard[21], ac[21], bc[21], ans[21], carry = 0;
    char n[21], a[21], b[21];
    gets(n);
    gets(a);
    gets(b);
    int countA = 0, countB = 0, countAns = 0;
    
    for(int i = 0; i < 21; i++){
        standard[i] = 10;
        ac[i] = 0;
        bc[i] = 0;
    }
    
    int lenn = strlen(n);
    for(int i = 0; i < lenn; i++){
        standard[i] = n[i] == '0' ? 10 : n[i] - '0';
    }
    reverse(standard, standard + lenn);
    
    int lena = strlen(a);
    int lenb = strlen(b);
    for(int i = lena - 1; i >= 0; i--){
        ac[countA++] = a[i] - '0';
    }
    for(int i = lenb - 1; i >= 0; i--){
        bc[countB++] = b[i] - '0';
    }
    
//    while(a != 0){
//        ac[countA++] = a % 10;
//        a /= 10;
//    }
//    while(b != 0){
//        bc[countB++] = b % 10;
//        b /= 10;
//    }
    
    for(int i = 0; i < countA || i < countB; i++){
        int temp = ac[i] + bc[i] + carry;
        ans[i] = temp % standard[i];
        carry = temp / standard[i];
        countAns++;
    }
    
    while(carry != 0){
        ans[countAns] = carry % standard[countAns];
        carry /= standard[countAns];
        countAns++;
    }
    countAns--;
    
    while(ans[countAns] == 0 && countAns >= 0){
        countAns--;
    }
    if(countAns < 0){
        printf("0");
    }
    for(int i = countAns; i >= 0; i--){
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
    
    
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//    using namespace std ;
//    int main() {
//        int num[20] , n = 0 , i , j , tmp , res[22] = {0} , len1 , len2 , last = 0 , k = 0 , tmp2 ;
//        char temp , a[21] , b[21] ;
//        scanf("%c",&temp) ;
//        while ( temp != '\n' ){
//            num[n++] = (temp-'0') ;
//            scanf("%c",&temp);
//        }
//        n-- ;
//        cin >> a >> b ;
//        len1 = strlen(a) ;
//        len2 = strlen(b) ;
//        for ( i = len1 - 1 , j = len2 - 1 ;  ; i-- , j-- , k++ , n--  ){
//            if ( i < 0 && j < 0 )
//                break ;
//            int c = ( i >= 0 ) ? ( a[i] - '0' ) : 0 ;
//            int d = ( j >= 0 ) ? ( b[j] - '0' ) : 0 ;
//            tmp2 = ( num[n] != 0 ) ? num[n] : 10 ;
//            tmp = c + d ;
//            res[k] = (last+tmp) % tmp2 ;
//            last = (tmp+last) / tmp2 ;
//        }
//        if ( last )
//            res[k] = last ;
//        while ( res[k] == 0 && k >= 0 ) k-- ;
//        if ( k < 0 && res[0] == 0 )
//            cout << 0 ;
//        for  ( i = k  ; i >=0  ; i-- )  {
//            cout << res[i] ;
//        }
//        cout << endl ;
//        return 0 ;
//    }
}
