# Summary
  This project is done at 21-Jun-2021. In this game, there are many structures which could be updated. This is a C++ learning project so that there are many drawbacks in this project. 
  In this summary, I'd like to state some drawbacks in this project.
  
  First is the wall part. According to the structure of the project, the hardest part is the wall. The body and wall around the map could be both regarded as walls because snake could die when it hit its body or the wall. The body is updated every move. However, due to the structure of the body and wall, this process is time consuming. In the body part, double link-list is used to store the location of the body and two dimension char type stores the wall. Thus, it takes a lot of time to read the location and the wall. In addition, I didn't figure out how to read data in list for a objective and how to return a value with two dimension char type. Thus, I use vector<pair<int, int>> and vector<string> type to transfer data from objective "Body" and "Gamemap" (wall). I know this approach is not efficient and I am going to looking for more efficient way in the future.
  
  Secondly, this project is like embedded C programming. There is a loop (while(1)) to excute all the commands. I guess this is not an efficient way to do this project. Therefore, the second future work is to find an advance sturcture such as multithreading.
  
