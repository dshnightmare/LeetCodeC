#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
	TrieNode() : flag(false){
	}
	unordered_map<char, TrieNode*> next;
	bool flag;
};

class Trie {
public:
	Trie(){
		root = new TrieNode();
		root->flag = true;
	}
	
	void insert(string word){
		TrieNode *cur = root;
		for(int i = 0; i < word.length(); i++){
			if(cur->next.find(word[i]) == cur->next.end())
				cur->next[word[i]] = new TrieNode();
			cur = cur->next[word[i]];
		}
		cur->flag = true;
	}
	
	bool search(string word){
		TrieNode *cur = root;
		for(int i = 0; i < word.length(); i++){
			if(cur->next.find(word[i]) == cur->next.end())
				return false;
			cur = cur->next[word[i]];
		}
		return cur->flag;
	}
	
	bool startsWith(string prefix){
		TrieNode *cur = root;
		for(int i = 0; i < prefix.length(); i++){
			if(cur->next.find(prefix[i]) == cur->next.end())
				return false;
			cur = cur->next[prefix[i]];
		}
		return true;
	}
	
private:
	TrieNode *root;
};