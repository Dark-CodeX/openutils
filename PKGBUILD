pkgname="openutils-optional"
pkgver="1.5.0"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/optional/master/optional/optional.hh")

sha512sums=("7422d667f3a2a8d24b67c89c1d5565190649aa1af5736862575dd04513c92ee526f031a2f96fe6cac1ae796ec7058249f4d4952bf064c8f0afc30848a3b9d749")

package() {
	echo "Memory Safe Value Returning Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/optional"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/optional/optional.hh"
	echo "Done!"
}
