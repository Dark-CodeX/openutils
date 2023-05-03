pkgname="openutils-optional"
pkgver="1.6.0"
pkgrel="2"
pkgdesc="OPTIONAL : The Error Handling Library"
arch=("x86_64" "i686")
conflicts=('openutils-optional')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/optional/master/optional/optional.hh")

sha512sums=("b2df0234262ce7930cfb10a72cbed39b7939862fe6039f6590857fb008345138bf17fac813bbf9336025dfafed680c9c8811c4b8e7c6cdc171d72c04d352eb1b")

package() {
	echo "OPTIONAL : The Error Handling Library"
	mkdir -p "${pkgdir}/usr/include/openutils/optional"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/optional/optional.hh"
	echo "Done!"
}
