#include "User.h"
#include "Controller.h" // Incluye Controller solo en el archivo fuente

User::User()
{
  get_file_data();
}
void User::print()
{
  cout << User::videos[0]->serialized_data() << endl;
}
void User::get_file_data()
{
  utils::get_data_movies(videos, "../mydata.csv");
}

void User::save_movie()
{
  // Implementación para guardar una película
}

void User::save_serie()
{
  // Implementación para guardar una serie
}

void User::rank_movie()
{
  // Implementación para rankear una película
}

void User::rank_serie()
{
  // Implementación para rankear una serie
}

void User::save_to_file()
{
  // Implementación para guardar datos en un archivo
}