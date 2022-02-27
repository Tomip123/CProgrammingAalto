#include "book.h"
#include <stdlib.h>
#include <string.h>

// / Date in numeric format

// /**
//  * \brief Day of a year structure
//  *
//  */
// struct date
// {
// 	unsigned char day;
// 	unsigned char month;
// 	int year;
// };

// /**
//  * \brief A book data structure
//  *
//  */
// struct book
// {
// 	char id[10];			  //!< The identifier of the the book
// 	char *title;			  //!< Title of the book
// 	char *author;			  //!< Author of the book
// 	struct date release_date; //!< The release date of the book
// };

// int init_book(struct book *p_book, const char *p_id, const char *p_title, const char *p_author, struct date release);

// struct book *add_to_collection(struct book *collection, unsigned int size, struct book new_book);

// #endif

/**
 * \brief Initializes a book for the collection.
 *
 * \param p_book The book to be initialized.
 * \param p_id The book identifier string
 * \param p_title The book title string
 * \param p_author The book author string
 * \param release The release date of the book
 * \returns 0 if the book identifier is not valid. The identifier is invalid
 * 			  if the stated book identifier has more than 9 characters.
 * \returns 1 if the book can be initialized.
 */
int init_book(struct book *p_book,
			  const char *p_id,
			  const char *p_title,
			  const char *p_author,
			  struct date release)
{
	// allocate memory for the title and author strings
	p_book->title = (char *)malloc(strlen(p_title) + 1);
	p_book->author = (char *)malloc(strlen(p_author) + 1);

	// check if the title and author strings were allocated
	if (!p_book->title || !p_book->author)
	{
		// free the title and author strings
		free(p_book->title);
		free(p_book->author);

		// return 0 if the title and author strings were not allocated
		return 0;
	}

	// copy the title and author strings
	strcpy(p_book->title, p_title);
	strcpy(p_book->author, p_author);

	// check if the book identifier is valid
	if (strlen(p_id) > 9)
	{
		// free the title and author strings
		free(p_book->title);
		free(p_book->author);

		// return 0 if the book identifier is not valid
		return 0;
	}

	// copy the book identifier
	strcpy(p_book->id, p_id);

	// copy the release date
	p_book->release_date = release;

	// return 1 if the book can be initialized
	return 1;
}

/**
 * \brief Adds a book to the collection. The collection is an array, and the
 * array should be reallocated to store the new book.
 *
 * \param collection The array of books representing the collection
 * \param size The number of books in the current collection
 * \param new_book The new book to be copied to the collection
 * \return A pointer to enlarged collection
 */
struct book *add_to_collection(struct book *collection,
							   unsigned int size,
							   struct book new_book)
{
	// allocate the author dynamically
	collection = (struct book *)realloc(collection, (size + 1) * sizeof(struct book));

	// check if the collection was reallocated
	if (!collection)
	{
		// return NULL if the collection was not reallocated
		return NULL;
	}

	// copy the new book to the collection
	collection[size] = new_book;

	// return the collection
	return collection;
}
	
