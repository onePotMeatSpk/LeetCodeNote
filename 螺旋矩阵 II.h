#pragma once
#include<vector>
using namespace std;
//����59
//��Ŀ���������� II
//��Ŀ����������һ�������� n ������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix ��


//˼·��ģ���������������

enum DIRECTION
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n, 0));//��������
    int end = n * n;//��������
    int count = 1;//��ǰҪ������

    DIRECTION derection = RIGHT;//��ǰ�н�����
    int borderLeft = -1, borderRight = n, borderUp = -1, borderDown = n;//��ʼ�����߽�
    int border = borderRight;//��ǰ�н�����ı߽�
    int base = 0;//��ǰ����������/��
    int i = 0;//��ǰ������/���е�λ��
    bool flag = 0;//��ʾ��ǰ�н������У��жϵ�ǰλ��i��߽�border��ϵ��Ӧ��>����<��0��>��1��<

    while (count <= end)
    {
        //
        //�����н�����ͬ����䵱ǰ��/��
        for (; flag ? i > border : i < border;)
        {
            switch (derection)
            {
            case RIGHT://����RIGHT�������������
                //��ǰ����ΪRIGHT��base = 0��i < border = borderRight��i��0��ʼ
                //��ʾ��ǰ��������0�У��ĵ�[0, borderRight)�У�ÿ��һ�У���i++�������У���count++��������
                ret[base][i++] = count++;
                break;
            case DOWN:
                ret[i++][base] = count++;
                break;
            case LEFT:
                ret[base][i--] = count++;
                break;
            case UP:
                ret[i--][base] = count++;
                break;
            }
        }

        //��䵱ǰ��/�����
        //���¸�����
        switch (derection)
        {
        case RIGHT://����RIGHT�������������
            borderUp++;//���¾ɱ߽磬��ǰ�н�������RIGHT�����ıض��Ǿ��󶥲����ʶ�borderUp++����ʾ�����߽�����
            derection = DOWN;//���н����򣬵�ǰ�н�������RIGHT�������������ض����¹գ���ʼ�������Ҳ�
            flag = 0;//�����жϷ��ţ���ǰ�н�������RIGHT�������������ض����¹գ�Ӧ����ײ��߽�Ƚϴ�С������Ӧ��<
            border = borderDown;//�������н�����ı߽磬��ǰ�н�������RIGHT�������������ض����¹գ��߽�Ӧ�ǵײ��߽�
            base = --i;//�������н��������/�У���ǰ�н�������RIGHT�����ʱ�����һ��i++������i�Ѿ�Խ��borderRight��Ӧ��--i���������ұ߽磬�������Ҳ�
            i = borderUp + 1;//�·���Ӻδ���ʼ��������ǰ�н�������RIGHT�������������ض����¹գ�Ӧ�ôӶ�����ʼ����
            break;
        case DOWN:
            borderRight--;
            derection = LEFT;
            flag = 1;
            border = borderLeft;
            base = --i;
            i = borderRight - 1;
            break;
        case LEFT:
            borderDown--;
            derection = UP;
            flag = 1;
            border = borderUp;
            base = ++i;
            i = borderDown - 1;
            break;
        case UP:
            borderLeft++;
            derection = RIGHT;
            flag = 0;
            border = borderRight;
            base = ++i;
            i = borderLeft + 1;
            break;
        }
    }

    return ret;
}