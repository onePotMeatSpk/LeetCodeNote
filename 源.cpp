#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<time.h>
#include"��������.h"
#include"������.h"
#include"���������������г��ֵĴ���.h"
#include"0��n-1��ȱʧ������.h"
#include"��������������ĺ����.h"
#include"���������ֳ��ֵĴ���.h"
#include"��Ϊs����������.h"
#include"��Ϊs��������������.h"
#include"��ת����˳��.h"
#include"����ת�ַ���.h"
#include"�������ڵ����ֵ.h"
#include"���е����ֵ.h"
#include"n��ɸ�ӵĵ���.h"
#include"ԲȦ�����ʣ�µ�����.h"
#include"��Ʊ���������.h"
#include"��1+2+��+n.h"
#include"���üӼ��˳����ӷ�.h"
#include"���ֵ��ȥ��СֵС�ڻ����num������������.h"
#include"����Ӿ���.h"
#include"����������ĳֵ����Ϊ���С���м���ȣ��ұߴ����ʽ.h"
#include"�����е��������.h"
#include"��������ÿk���ڵ�֮������.h"
#include"ɾ������������ֵ�ظ����ֵĽڵ�.h"
#include"������������ת����˫������.h"

using namespace std;

int main()
{
    vector<int> v = { 6,4,7,2,5,NULL,9,1,3,NULL,NULL,8 };
    TreeNode* tt = createTree(v);
    printTreePre(tt);

    cout << "```````````````````" << endl;

    tt = convert(tt);
    TreeNode* pre = NULL;
    while (tt)
    {
        pre = tt;
        cout << tt->val << endl;
        tt = tt->right;
    }

    tt = pre;
    while (tt)
    {
        pre = tt;
        cout << tt->val << endl;
        tt = tt->left;
    }

    return 0;
}

