#ifndef CLICONTROLLER_H
#define CLICONTROLLER_H

#include "pkgresolver.h"
#include "rulecontroller.h"
#include "pacmanrunner.h"

#include <QObject>

class CliController : public QObject
{
	Q_OBJECT

public:
	explicit CliController(QObject *parent = nullptr);

public slots:
	void parseCli();

private:
	void rebuild();
	void update(const QStringList &pks);
	void create(const QString &pkg, const QStringList &rules);
	void list(bool detail);
	void clear();
	void frontend();
	void setFrontend(const QStringList &frontend);
	void printArgs();

	void testEmpty(const QStringList &args);

	RuleController *_rules;
	PkgResolver *_resolver;
	PacmanRunner *_runner;
};

#endif // CLICONTROLLER_H
