#include <string>
using namespace std;
class TrieNode {
public:
	TrieNode() : flag(false){
		for(int i = 0; i < 26; i++)
			next[i] = nullptr;
	}
	TrieNode *next[26];
	bool flag;
};

class WordDictionary {
public:
	
	WordDictionary(){
		root = new TrieNode();
		root->flag = true;
	}
	
    // Adds a word into the data structure.
    void addWord(string word) {
		TrieNode *cur = root;
		for(int i = 0; i < word.length(); i++){
			if(cur->next[word[i] - 'a'] == nullptr)
				cur->next[word[i] - 'a'] = new TrieNode();
			cur = cur->next[word[i] - 'a'];
		}
		cur->flag = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search_help(word, root);
    }
	
private:
	bool search_help(string word, TrieNode *start){
		TrieNode *cur = start;
		for(int i = 0; i < word.length(); i++){
			if(word[i] == '.'){
				for(int j = 0; j < 26; j++){
					if(cur->next[j] != nullptr && search_help(word.substr(i + 1), cur->next[j]))
						return true;
				}
				return false;
			}
			if(cur->next[word[i] - 'a'] == nullptr)
				return false;
			cur = cur->next[word[i] - 'a'];
		}
		return cur->flag;
	}
	
	TrieNode *root;
};