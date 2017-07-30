#ifndef RULECONTROLLER_H
#define RULECONTROLLER_H

#include <QObject>
#include <QHash>
#include <QDir>

class RuleController : public QObject
{
	Q_OBJECT

public:
	explicit RuleController(QObject *parent = nullptr);

	void createRule(const QString &pkg, const QStringList &deps);

	QStringList analyze(const QString &pkg) const;

private:
	mutable QMultiHash<QString, QString> _rules;

	void readRules() const;
};

#endif // RULECONTROLLER_H
