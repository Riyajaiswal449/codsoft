import pandas as pd

# Sample data: movies and their genres
movies = pd.DataFrame({
    'movie_id': [1, 2, 3, 4, 5],
    'title': ['Movie A', 'Movie B', 'Movie C', 'Movie D', 'Movie E'],
    'genres': ['Action|Adventure', 'Action|Comedy', 'Adventure|Fantasy', 'Comedy|Drama', 'Action|Drama']
})

# User preferences (genres the user likes)
user_preferences = ['Action', 'Adventure']

# Function to recommend movies based on content
def recommend_movies_based_on_content(user_preferences, movies):
    recommendations = []
    for _, row in movies.iterrows():
        genres = row['genres'].split('|')
        if any(genre in user_preferences for genre in genres):
            recommendations.append(row['title'])
    return recommendations

print("Content-Based Recommendations:")
print(recommend_movies_based_on_content(user_preferences, movies))
