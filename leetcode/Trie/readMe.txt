208.ʵ��һ�� Trie (ǰ׺��)������ insert, search, �� startsWith ������������

ʾ��:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // ���� true
trie.search("app");     // ���� false
trie.startsWith("app"); // ���� true
trie.insert("app");   
trie.search("app");     // ���� true
˵��:

����Լ������е����붼����Сд��ĸ a-z ���ɵġ�
��֤���������Ϊ�ǿ��ַ�����