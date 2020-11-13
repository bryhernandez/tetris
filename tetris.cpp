#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getmap(int piece) {
  vector<vector<int>> map;
  if(piece == 1) {
      map.push_back({0});
      map.push_back({0, 0, 0, 0});
  }
  if(piece == 2) {
      map.push_back({0, 0});
  }
  if(piece == 3) {
      map.push_back({0, 0, 1});
      map.push_back({1, 0});
  }
  if(piece == 4) {
      map.push_back({1, 0, 0});
      map.push_back({0, 1});
  }
  if(piece == 5) {
      map.push_back({1, 0, 1});
      map.push_back({0, 0, 0});
      map.push_back({1, 0});
      map.push_back({0, 1});
  }
  if(piece == 6) {
      map.push_back({2, 0});
      map.push_back({0, 1, 1});
      map.push_back({0, 0});
      map.push_back({0, 0, 0});
  }
  if(piece == 7) {
      map.push_back({0, 2});
      map.push_back({1, 1, 0});
      map.push_back({0, 0});
      map.push_back({0, 0, 0});
  }

  return map;
}

int getmatches(vector<int>& board, vector<int>& piece) {
  int total = 0;
  for(int i = 0; i < board.size() - (piece.size() - 1); i++) {
    bool works = true;
    int diff = board[i] - piece[0];
    for(int j = 1; j < piece.size(); j++) {
      if(diff != board[i+j] - piece[j])
        works = false;
    }
    if(works)
      total++;
  }
  return total;
}


int main() {
  int size, piece;

  cin >> size;
  cin >> piece;

  vector<int> board;
  for(int i = 0; i < size; i++){
    int temp;
    cin >> temp;
    board.push_back(temp);
  }

  vector<vector<int>> map;
  map = getmap(piece);

  int total;

  for(auto i : map)
    total += getmatches(board, i);

  cout << total;

}
