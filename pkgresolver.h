#ifndef PKGRESOLVER_H
#define PKGRESOLVER_H

#include "rulecontroller.h"

#include <QObject>
#include <QSettings>

class PkgResolver : public QObject
{
	Q_OBJECT

public:
	explicit PkgResolver(QObject *parent = nullptr);

	QStringList listPkgs() const;
	QStringList listDetailPkgs() const;

	void updatePkgs(const QStringList &pkgs, RuleController *rules);
	void clear();

private:
	typedef QMap<QString, QSet<QString>> PkgInfos;

	QSettings *_settings;

	PkgInfos readPkgs() const;
};

#endif // PKGRESOLVER_H
