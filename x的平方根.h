#pragma once
#include<vector>
using namespace std;
//����69
//��Ŀ��x��ƽ����
//��Ŀ����������һ���Ǹ����� x �����㲢���� x �� ����ƽ���� ��
//          ���ڷ������������������ֻ���� �������� ��С�����ֽ��� ��ȥ ��


//���ַ���ע��ʹ��longlong���ͣ��Է�ֹ���
int mySqrt(int x) {
    int l = 0, r = x, mid = 0;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        long long sq0 = (long long)mid * mid;
        long long sq1 = (long long)(mid + 1) * (mid + 1);

        if (sq0 > x)
            r = mid - 1;
        else if (sq0 == x || (sq0 < x && sq1 > x))
            return mid;
        else if (sq1 <= x)
            l = mid + 1;
    }

    return -1;
}