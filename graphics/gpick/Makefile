# $NetBSD: Makefile,v 1.7 2017/08/24 20:03:21 adam Exp $

DISTNAME=	gpick-gpick-0.2.5
PKGNAME=	${DISTNAME:S/gpick-//}
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	-http://github.com/thezbyg/gpick/archive/gpick-0.2.5.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/thezbyg/gpick/
COMMENT=	Advanced color picker
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons
USE_TOOLS+=	pkg-config

SCONS=		${PREFIX}/bin/scons
SCONS_ARGS+=	DESTDIR=${DESTDIR}${PREFIX}
SCONS_ARGS+=	PKGMANDIR=${PKGMANDIR}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS} install

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
