#include <iostream>
#include <vector>
using namespace std;
uint hash1( const string & key, uint table_size )
{
  uint hash_val = 0;
  for( auto character : key )
  {
    hash_val = 37 * hash_val + character;
  }
  return hash_val % table_size;
}

uint hash2( const string & key, uint table_size )
{
  uint hash_val = 2166136261;
  for( auto character : key )
  {
    hash_val = (hash_val ^ character) * 16777619;
  }
  return hash_val % table_size;
}
bool collition(string test)
{
  return test != "NULL";
}

int main()
{
  string words1[99173];
  string words2[99173];
  uint collitions1 = 0;
  uint collitions2 = 0;
  string word;
  vector<string> words;
  while( !cin.eof() )
  {
    cin >> word;
    if( ! cin.eof() )
    {
      words.push_back(word);
    }
  }
  for(int i = 0; i<99173; i++)
    {
      words1[i] = "NULL";
      words2[i] = "NULL";
    }
  for(int i = 0; i<99171; i++){
    if(collition(words1[hash1(words.at(i),99173)]))
      {
	collitions1++;
      }
    else
      {
	words1[hash1(words.at(i),99173)] = words.at(i);
      }
    if(collition(words2[hash2(words.at(i),99173)]))
      {
	collitions2++;
      }
      else
	{
	  words2[hash2(words.at(i),99173)] = words.at(i);
	}
    }
  cout << collitions1 << " " << collitions2 << endl;
  
  return 0;
      
}
