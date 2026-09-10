#include <iostream>
#include <vector>
#include <string>
using namespace std;

class player
{
private:
    int code, matchplayed, runs, notout;
    string name;
    float avgruns;

public:

    // Constructor
    player()
    {
        code = 0;
        matchplayed = 0;
        runs = 0;
        notout = 0;
        name = "";
        avgruns = 0.0;
    }

    // Input player details
    void getinfo()
    {
        cout << "\nEnter the cricketer details:" << endl;

        cout << "Enter the player code: ";
        cin >> code;

        cout << "Enter the name of the player: ";
        cin >> name;

        cout << "Enter the total matches played by the player: ";
        cin >> matchplayed;

        cout << "Enter the total runs of the player: ";
        cin >> runs;

        cout << "Enter number of times the player was not out: ";
        cin >> notout;
    }

    // Calculate average runs
    void avg_runs()
    {
        if (matchplayed == 0)
        {
            cout << "Average cannot be calculated." << endl;
            return;
        }

        avgruns = (float)runs / matchplayed;

        cout << "Player: " << name << "\tAverage Runs: " << avgruns << endl;
    }

    // Display player details
    void display()
    {
        cout << "\nPlayer Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Matches Played: " << matchplayed << endl;
        cout << "Runs: " << runs << endl;
        cout << "Not Out: " << notout << endl;
    }

    // Getter functions
    int getcode()
    {
        return code;
    }

    int getruns()
    {
        return runs;
    }

    // Sort players according to runs
    void display_sorted(vector<player> &plist)
    {
        int n = plist.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (plist[j].getruns() > plist[j + 1].getruns())
                {
                    player temp = plist[j];
                    plist[j] = plist[j + 1];
                    plist[j + 1] = temp;
                }
            }
        }

        cout << "\nPlayers sorted according to total runs:" << endl;

        for (int i = 0; i < n; i++)
        {
            plist[i].display();
        }
    }
};

int main()
{
    vector<player> people;

    int ch, n = 0;

    cout << "Cricket Players:" << endl;
    cout << "1. Add players." << endl;
    cout << "2. Display average runs of a single player." << endl;
    cout << "3. Display average runs of all players." << endl;
    cout << "4. Display players sorted according to total runs." << endl;
    cout << "5. Exit." << endl;

    while (true)
    {
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
            {
                int count;

                cout << "How many players do you want to enter (max 10): ";
                cin >> count;

                if (count <= 0 || count > 10)
                {
                    cout << "Please enter a valid number." << endl;
                    break;
                }

                people.resize(count);

                for (int i = 0; i < count; i++)
                {
                    people[i].getinfo();
                }

                n = count;

                break;
            }

            case 2:
            {
                if (n == 0)
                {
                    cout << "Please enter player details first." << endl;
                    break;
                }

                int search;

                cout << "Enter player code: ";
                cin >> search;

                bool found = false;

        		for (int i = 0; i < people.size(); i++)
				{
    				if (people[i].getcode() == search)
    				{
        				people[i].avg_runs();
        				found = true;
       					break;
    				}
				}


                if (!found)
                {
                    cout << "Player not found." << endl;
                }

                break;
            }

            case 3:
            {
                if (n == 0)
                {
                    cout << "Please enter player details first." << endl;
                    break;
                }

        		for (int i = 0; i < people.size(); i++)
				{
    				people[i].avg_runs();
				}

                break;
            }

            case 4:
            {
                if (!people.empty())
                {
                    people[0].display_sorted(people);
                }
                else
                {
                    cout << "Enter player details first." << endl;
                }

                break;
            }

            case 5:
            {
                cout << "Exiting program..." << endl;
                return 0;
            }

            default:
            {
                cout << "Invalid choice." << endl;
            }
        }
    }

    return 0;
}

