
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>

void printVector( std::vector<int> aRange )
{
    for ( auto sValue: aRange )
    {
        std::cout << sValue << " ";
    }

    std::cout << "\n";
}

void printCount( std::map<int, int> aMap )
{
    for ( auto it = aMap.begin(); 
          it != aMap.end(); 
          ++it ) 
    {
        std::cout << it->first << " : " << it->second << '\n';
    }
}

std::map<int, int> getCountInRange( std::vector<int> aRange )
{
    std::map<int, int>  sCount;

    for ( auto sIndex: aRange )
    {
        ++sCount[sIndex];
    }

    return sCount;
}

int getMaxCount( std::map<int, int> aMap )
{
    int sMaxCount = 0;

    for( auto it = aMap.begin();
         it != aMap.end();
         ++it )
    {
        if ( sMaxCount < it->second )
        {
            sMaxCount = it->second;
        }
    }

    return sMaxCount;
}

std::vector<std::pair<int,int>> getMostFrequentElement( std::vector<int> aRange )
{
    std::map<int, int>  sCount;
    
    sCount = getCountInRange( aRange );

    //printVector( aRange );
    //printCount( sCount );

    int sMaxCount = getMaxCount( sCount );

    std::vector<std::pair<int,int>>  sResult;

    for ( auto it = sCount.begin();
          it != sCount.end();
          ++it )
    {
        if ( sMaxCount == it->second )
        {
            sResult.push_back( std::make_pair( it->first, it->second ) );
        }
    }

    return sResult;
}

int main( int argc, char * argv[] )
{
    std::vector<int> sRange = { 1, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5 };
    auto sResult = getMostFrequentElement( sRange );

    for ( auto it = sResult.begin();
          it != sResult.end();
          ++it )
    {
        std::cout << it->first << " : " << it->second << "\n";
    }

    return 0;
}
