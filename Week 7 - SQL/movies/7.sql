SELECT title, rating FROM movies JOIN ratings ON movie_id = id WHERE year = 2010 AND rating > 0.0 ORDER BY rating; 
