380.���һ��֧����ƽ�� ʱ�临�Ӷ� O(1) �£�ִ�����²��������ݽṹ��

insert(val)����Ԫ�� val ������ʱ���򼯺��в�����
remove(val)��Ԫ�� val ����ʱ���Ӽ������Ƴ����
getRandom������������м����е�һ�ÿ��Ԫ��Ӧ������ͬ�ĸ��ʱ����ء�
ʾ�� :

// ��ʼ��һ���յļ��ϡ�
RandomizedSet randomSet = new RandomizedSet();

// �򼯺��в��� 1 ������ true ��ʾ 1 ���ɹ��ز��롣
randomSet.insert(1);

// ���� false ����ʾ�����в����� 2 ��
randomSet.remove(2);

// �򼯺��в��� 2 ������ true ���������ڰ��� [1,2] ��
randomSet.insert(2);

// getRandom Ӧ������� 1 �� 2 ��
randomSet.getRandom();

// �Ӽ������Ƴ� 1 ������ true ���������ڰ��� [2] ��
randomSet.remove(1);

// 2 ���ڼ����У����Է��� false ��
randomSet.insert(2);

// ���� 2 �Ǽ�����Ψһ�����֣�getRandom ���Ƿ��� 2 ��
randomSet.getRandom();