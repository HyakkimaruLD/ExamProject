#include <iostream>
#include "AnimeContainer.h"

using namespace std;

void printMenu() {
    cout << "----------------------------------" << endl;
    cout << "1. Show all anime" << endl;
    cout << "2. Add anime" << endl;
    cout << "3. Del anime" << endl;
    cout << "4. Edit anime" << endl;
    cout << "5. Search anime by title" << endl;
    cout << "6. Search anime by genre" << endl;
    cout << "7. Save to file" << endl;
    cout << "8. Download from file" << endl;
    cout << "9. Exit" << endl;
    cout << "Select an option: " << endl;
    cout << "----------------------------------" << endl;
}

int main() {
    AnimeContainer container;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "----------------------------------" << endl;
            cout << "All anime:" << endl;
            container.printAll();
            break;
        }
        case 2: {
            cout << "----------------------------------" << endl;
            int type;
            cout << "Select the type of anime (1 - TVShow, 2 - Movie): ";
            cin.ignore();
            cin >> type;

            string title, genre;
            int day, month, year;
            cout << "Enter a name: ";
            cin >> title;
            cout << "Enter genre: ";
            cin >> genre;
            cout << "Enter the release date (day month year): ";
            cin >> day >> month >> year;
            Date releaseDate(day, month, year);

            if (type == 1) 
            {
                int seasons;
                cout << "Enter the number of seasons: ";
                cin >> seasons;
                container.addAnime(new TVShow(title, genre, releaseDate, seasons));
            }
            else if (type == 2) 
            {
                int duration;
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                container.addAnime(new Movie(title, genre, releaseDate, duration));
            }
            break;
        }
        case 3: {
            cout << "----------------------------------" << endl;
            string title;
            cout << "Enter the name of the anime to delete: ";
            cin >> title;
            container.removeAnime(title);
            break;
        }
        case 4: {
            cout << "----------------------------------" << endl;
            string title;
            cout << "Enter the name of the anime to edit: ";
            cin >> title;

            int type;
            cout << "Choose a new type of anime (1 - TVShow, 2 - Movie): ";
            cin >> type;

            string newTitle, genre;
            int day, month, year;
            cout << "Enter a new name: ";
            cin >> newTitle;
            cout << "Enter a new genre: ";
            cin >> genre;
            cout << "Enter the new release date (day month year): ";
            cin >> day >> month >> year;
            Date releaseDate(day, month, year);

            if (type == 1) 
            {
                int seasons;
                cout << "Enter a new number of seasons: ";
                cin >> seasons;
                container.editAnime(title, new TVShow(newTitle, genre, releaseDate, seasons));
            }
            else if (type == 2) 
            {
                int duration;
                cout << "Enter new duration (in minutes): ";
                cin >> duration;
                container.editAnime(title, new Movie(newTitle, genre, releaseDate, duration));
            }
            break;
        }
        case 5: {
            cout << "----------------------------------" << endl;
            string title;
            cout << "Enter the name of the anime to search: ";
            cin >> title;
            Anime* anime = container.searchByTitle(title);
            if (anime) 
            {
                anime->print();
            }
            else 
            {
                cout << "No anime with this title found." << endl;
            }
            break;
        }
        case 6: {
            cout << "----------------------------------" << endl;
            string genre;
            cout << "Enter a genre to search: ";
            cin >> genre;
            vector<Anime*> results = container.searchByGenre(genre);
            if (!results.empty()) {
                for (Anime* anime : results) 
                {
                    anime->print();
                }
            }
            else 
            {
                cout << "Anime with this genre was not found." << endl;
            }
            break;
        }
        case 7: {
            cout << "----------------------------------" << endl;
            string filename;
            cout << "Enter a file name to save: ";
            cin >> filename;
            container.saveToFile(filename);
            break;
        }
        case 8: {
            cout << "----------------------------------" << endl;
            string filename;
            cout << "Enter the name of the file to download: ";
            cin >> filename;
            container.loadFromFile(filename);
            break;
        }
        case 9: {
            cout << "----------------------------------" << endl;
            cout << "Exit the program." << endl;
            cout << "----------------------------------" << endl;
            break;
        }
        default: {
            cout << "Error!" << endl;
            break;
        }
        }
    } while (choice != 9);

    return 0;
}

