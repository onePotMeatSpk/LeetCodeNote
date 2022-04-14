#pragma once
#include<vector>
using namespace std;

bool verifyPostorderCore(vector<int>& postorder, int l, int r) {
    //���и�
    if (l == r) return true;
    //�ҵ���һ���ȸ�С�����֣�������Ϊmid
    int mid = r - 1;
    while ((mid >= l) && (postorder[mid] > postorder[r]))
        --mid;

    //�ޱȸ�С�����֣���ǰ��Χ�ڳ��˸�����������
    if (mid < l)    return verifyPostorderCore(postorder, l, r - 1);

    //���midǰ�Ƿ���Ȼ���ڱȸ�������֣����еĻ�˵�������������ǲ�������
    for (int i = mid - 1; i >= l; i--)
        if (postorder[i] > postorder[r])    return false;

    //�ޱȸ�������֣���ǰ��Χ�ڳ��˸�����������
    if (mid == r - 1)    return verifyPostorderCore(postorder, l, r - 1);

    //�����������У��ݹ���ȥ�ж����������Ƿ������
    return (verifyPostorderCore(postorder, l, mid) && verifyPostorderCore(postorder, mid + 1, r - 1));
}

bool verifyPostorder(vector<int>& postorder) {
    if (postorder.size() == 0)   return true;
    if (verifyPostorderCore(postorder, 0, postorder.size() - 1))  return true;
    else    return false;
}