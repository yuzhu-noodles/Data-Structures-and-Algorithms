#ifndef GRAPHMODEL_H
#define GRAPHMODEL_H

#define OK 1
#define ERROR 0
#define MAX_VERTEX 100
//ͼ������ö��
typedef enum
{
	DG,  //����ͼ
    UDG, //����ͼ
	DN,  //������
	UDN  //������
}GraphType;

//���ö�����������Ϊ�ַ������ͣ�ʹ��ʱҪmalloc
typedef char* VerTexType;
//����Ȩֵ����Ϊint
typedef int ArcType; 

#endif