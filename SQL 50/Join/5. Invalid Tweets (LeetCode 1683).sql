Question

Table: Tweets

Column Name	Type
tweet_id	int
content	varchar

A tweet is invalid if the number of characters in the content is greater than 15.

Write a solution to find the IDs of invalid tweets.

Table Example
tweet_id	content
1	Let us Code
2	More than fifteen characters
3	Short tweet
SQL Solution


SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;