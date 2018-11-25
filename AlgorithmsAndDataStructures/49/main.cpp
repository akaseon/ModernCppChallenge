
#include <map>
#include <string>
#include <iostream>
#include <cctype>

#define IS_CASE_SENSITIVITY     (false)

std::pair<int, std::map<char, int>> getTextFrequency( std::string aInput )
{
    std::map<char, int>     sFrequency;
    int                     sTextTotalCount = 0;

    for ( auto sValue : aInput )
    {
        if ( std::isalpha( sValue ) == 1 )
        {
            if ( IS_CASE_SENSITIVITY == false )
            {
                if ( sValue >= 'a' )
                {
                    sValue -= ( 'a' - 'A' );
                }
            }

            ++sFrequency[sValue];
            ++sTextTotalCount;
        }
    }

    return std::make_pair( sTextTotalCount, sFrequency );
}

void printFrequency( std::map<char, int> aFrequency )
{
    for ( auto sElement : aFrequency )
    {
        std::cout << sElement.first << " : " << sElement.second << "\n";
    }
}

std::map<char, std::pair<int, int> > getTextHistorgram( std::string aInput )
{
    std::pair<int, std::map<char,int>> sFrequency = getTextFrequency( aInput );


    std::map<char, std::pair<int, int>> sTextHistorgram;

    int sTextTotalCount = sFrequency.first;

    //printFrequency( sFrequency.second );
    for ( auto sElement : sFrequency.second )
    {
        sTextHistorgram[sElement.first] = std::make_pair( sElement.second,
                                                          sElement.second * 100 / sTextTotalCount );
    }

    return sTextHistorgram;
}

void printTextHistorgram( std::map<char, std::pair<int, int>>  aTextHistorgram )
{
    for ( auto sElement : aTextHistorgram )
    {
        std::cout << sElement.first << " -> Frequency : " << sElement.second.first << " , ";
        std::cout << "Percent : " << sElement.second.second << "\n";
    }
}

int main( int argc, char * argv[] )
{
    std::map<char, std::pair<int, int>> sTextHistorgram = getTextHistorgram( "Test Test 1234 ()" );

    printTextHistorgram( sTextHistorgram );

    return 0;
}
