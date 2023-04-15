pkgname="openutils-sstring"
pkgver="2.5.0"
pkgrel="8"
pkgdesc="Memory Safe String Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=("9f13e098138305f11c4c476463332e1ae13311991d4d50d820bd74de5d13ce108e0c0a5669a2c1d8d7b76bbd5688ca5283426a03be963bf5e481db8df3ebc2fa")

package() {
	echo "Memory Safe String Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
