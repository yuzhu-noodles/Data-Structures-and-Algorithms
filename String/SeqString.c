#include"SeqString.h"

void InitString_HeapString(HString* str)
{
	str->ch = NULL;
	str->length = 0;
}

Status StrAssign_HeapString(HString* str, char* chars)
{
	int len = strlen(chars);
	if (!len)
	{
		return ERROR;
	}
	InitString_HeapString(str);
	str->ch = (char*)malloc(len * sizeof(char));
	if (!str->ch)
	{
		exit(OVERFLOW);
	}
	for (int i = 0; i < len; i++)
	{
		str->ch[i] = chars[i];
	}
	str->length = len;
	return OK;
}

Status StrCopy_HeapString(HString* deststr, HString* srcstr)
{
	InitString_HeapString(deststr);
	if (IsEmpty_HeapString(srcstr))
	{
		printf("原字符串为空，复制失败！\n");
		return ERROR;
	}
	deststr->ch = (char*)malloc(sizeof(char) * srcstr->length);
	if (!deststr->ch)
	{
		exit(OVERFLOW);
	}
	for (int i = 0; i < srcstr->length; i++)
	{
		deststr->ch[i] = srcstr->ch[i];
	}
	deststr->length = srcstr->length;
	return OK;
}

Status IsEmpty_HeapString(HString* str)
{
	if (str->length == 0 || !str->ch)
	{
		return TRUE;
	}
	return FALSE;
}

//字符串比较
//str1 == str2   return 0
//str1 < str2    return 负数
//str1 > str2    return 正数
Status StrCompare_HeapString(HString* str1, HString* str2)
{
	for (int i = 0; i < str1->length && i < str2->length; i++)
	{
		//遇到不同的字符直接比较ASCII码
		if (str1->ch[i] != str2->ch[i])
		{
			if (str1->ch[i] > str2->ch[i])
				return str1->ch[i] - str2->ch[i];
		}
	}
	//字符都相等但长度不相等
	return str1->length - str2->length;
}

Status Concat_HeapString(HString* deststr, HString* str1, HString* str2)
{
	InitString_HeapString(deststr);
	deststr->length = str1->length + str2->length;
	deststr->ch = (char*)malloc(sizeof(char) * deststr->length);
	if (!deststr->ch)
		exit(OVERFLOW);
	for (int i = 0; i < str1->length; i++)
	{
		deststr->ch[i] = str1->ch[i];
	}
	for (int i = 0; i < str2->length; i++)
	{
		deststr->ch[str1->length + i] = str2->ch[i];
	}
	return OK;
}

Status SubString_HeapString(HString* deststr, HString* str, int pos, int len)
{
	InitString_HeapString(deststr);
	if (IsEmpty_HeapString(str))
	{
		return ERROR;
	}
	if (pos<1 || pos > str->length || len<0 || pos + len - 1>str->length)
	{
		return ERROR;
	}
	deststr->ch = (char*)malloc(sizeof(char) * len);
	if (!deststr->ch)
	{
		exit(OVERFLOW);
	}
	for (int i = 0; i < len; i++)
	{
		deststr->ch[i] = str->ch[pos + i];
	}
	deststr->length = len;
	return OK;
}

int Index_HeapString(HString* parent, HString* child, int pos)
{
	if (pos < 0) //表示没有匹配的字符串
	{
		return 0;
	}
	HString* substr = (HString*)malloc(sizeof(HString));
	InitString_HeapString(substr);
	int i = pos;  //记录起始位置
	while (i+child->length-1<=parent->length)
	{
		//截取子串
		SubString_HeapString(substr, parent, i, child->length);
		if (StrCompare_HeapString(substr, child) != EQ)
		{
			i++;
		}
		else
		{
			return i;
		}
	}
	free(substr);
	return 0;
}

Status StrDelete_HeapString(HString* str, int pos, int len)
{
	if (IsEmpty_HeapString(str))
		return ERROR;
	if (pos<1 || pos + len - 1>str->length || len < 0)
		return ERROR;
	for (int i = pos - 1; i + len < str->length; i++)
	{
		str->ch[i] = str->ch[i + len];
	}
	str->length -= len;
	//缩小分c配空间
	str->ch = (char*)realloc(str->ch, str->length * sizeof(char));
	return OK;
}

Status StrInsert_HeapString(HString* str, HString* insertstr, int pos)
{
	if (pos<1 || pos>str->length + 1)
		return ERROR;
	if (IsEmpty_HeapString(str))
		return ERROR;
	str->ch = (char*)realloc(str->ch, sizeof(char) * (str->length + insertstr->length));
	if (!str->ch)
		exit(OVERFLOW);
	for (int i = str->length - 1; i >= pos - 1; i--)  //为插入腾出位置
	{
		str->ch[i + insertstr->length] = str->ch[i];
	}
	//插入每个字符
	for (int i = 0; i < insertstr->length; i++)
	{
		str->ch[pos - 1 + i] = insertstr->ch[i];
	}
	str->length += insertstr->length;
	return OK;
}
void Print_HeapString(HString* str)
{
	if (str->length == 0 || !str->ch)
	{
		printf("堆字符串为空！\n");
		return;
	}
	for (int i = 0; i < str->length; i++)
	{
		printf("%c", str->ch[i]);
	}
	printf("\n");
}