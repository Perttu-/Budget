#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H
#include <QString>
#include <QtSql>


class DatabaseInterface
{
public:
   DatabaseInterface();

   QSqlError initializeDatabase();

   void addProfile(QString name, QString password);
   void editProfile();
   void deleteProfile();

   void addCategory(QString name, bool isIncome, dailyGoal, weeklyGoal, yearlyGoal, QString description);
   void editCategory();
   void deleteCategory();

   void addTransaction();
   void editTransaction();
   void deleteTransaction();

private:
   QString name;
   QString password;
   QSqlDatabase db;

};

#endif // DATABASEINTERFACE_H
