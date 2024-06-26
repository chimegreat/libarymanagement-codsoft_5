
#include <iostream>
#include <string>
#include <limits>
#include <ctime>

// Utility function to print colored text
void print_color(const std::string &text, const std::string &color_code)
{
    std::cout << "\033[" << color_code << "m" << text << "\033[0m";
}

class library_manage
{
public:
    std::string title[3] = {"MY CODESOFT JOURNEY", "C++ TEMPLATES", "EFFECTIVE LIBRARY MANAGEMENT"};
    std::string author[3] = {"OKORO GREAT", "JOHAN STRASTOUP", "WOLE SOYINKA"};
    std::string Isbn[3] = {"CD123_S", "123CB", "1234CV"};
    std::string title_user;
    std::string author_user;
    std::string user_isbn;

    void srch_bok()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        print_color("Note: Enter All Characters In Capital Letters!!\n\n", "1;33"); // Yellow
        print_color("Enter The Book Title: ", "1;34");                              // Blue
        std::getline(std::cin, title_user);
        print_color("Enter Author's Name: ", "1;34");
        std::getline(std::cin, author_user);
        print_color("Enter Book's ISBN: ", "1;34");
        std::getline(std::cin, user_isbn);

        bool found = false;
        for (int i = 0; i < 3; i++)
        {
            if (title_user == title[i] && author_user == author[i] && user_isbn == Isbn[i])
            {
                print_color("Book Found!\n", "1;32"); // Green
                std::cout << "BOOK Title: " << title[i] << " | Author: " << author[i] << " | ISBN No: " << Isbn[i] << std::endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            print_color("Invalid Input!! Please Enter All Characters In Capital Letters!!\n", "1;31"); // Red
        }
    }
    // we are burrowing
    bool burrow()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string Title_burrow;
        print_color("Note: Enter All Characters In Capital Letters!!\n", "1;33");
        print_color("Enter Book Title: ", "1;34");
        std::getline(std::cin, Title_burrow);

        for (int i = 0; i < 3; i++)
        {
            if (title[i] == Title_burrow)
            {
                print_color("Available!!\n", "1;32");
                std::cout << "You borrowed: " << title[i] << "\n";
                print_color("To be returned in 14 days.\n", "1;32");
                return true;
            }
        }
        print_color("Book not available.\n", "1;31");
        return false;
    }

    void check_out()
    {
        if (burrow())
        {
            print_color("Book Checked Out Successfully!\n", "1;32");
        }
    }
    // we are returnin boook
    void return_bok()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        print_color("Note: Enter All Characters In Capital Letters!!\n\n", "1;33");
        print_color("Enter The Book Title: ", "1;34");
        std::getline(std::cin, title_user);
        print_color("Enter Author's Name: ", "1;34");
        std::getline(std::cin, author_user);
        print_color("Enter Book's ISBN: ", "1;34");
        std::getline(std::cin, user_isbn);

        bool found = false;
        for (int i = 0; i < 3; i++)
        {
            if (title_user == title[i] && author_user == author[i] && user_isbn == Isbn[i])
            {
                print_color("Thank you for returning the book!\n", "1;32");
                std::cout << "BOOK Title: " << title[i] << " | Author: " << author[i] << " | ISBN No: " << Isbn[i] << std::endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            print_color("Invalid Book Information.\n", "1;31");
        }
    }
};

void print_welcome_banner()
{
    print_color("====================================\n", "1;36"); // Cyan
    print_color("  WELCOME TO THE SCHOOL LIBRARY  \n", "1;36");
    print_color("====================================\n", "1;36");
}

void print_menu()
{
    print_color("\nMenu Options:\n", "1;33");
    std::cout << "1. Search For a Book\n";
    std::cout << "2. Borrow a Book\n";
    std::cout << "3. Return a Book\n";
    std::cout << "0. Exit the Library\n";
    print_color("Please enter your choice: ", "1;34");
}

int main()
{
    print_welcome_banner();
    library_manage lin;

    while (true)
    {
        print_menu();
        int User_input;
        std::cin >> User_input;

        switch (User_input)
        {
        case 1:

            lin.srch_bok();
            break;
        case 2:
            lin.check_out();
            break;
        case 3:
            lin.return_bok();
            break;
        case 0:
            print_color("Thank You for Using The Library!!\n", "1;32");
            return 0;
        default:
            print_color("Invalid Option. Please Try Again.\n", "1;31");
            break;
        }
    }

    return 0;
}
