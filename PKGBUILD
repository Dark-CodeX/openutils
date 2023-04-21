pkgname="openutils-vector"
pkgver="2.0.0"
pkgrel="4"
pkgdesc="Vectors in C/C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("d2b59dcfacc89ee238b904f195f0e3d3786a256243d1c31e80df1e01544b78ff09138d2a490c7af8306c3fae00c469bc8ec86bf55cc4d1db10b8d68212bebb27")

package() {
	echo "Vectors in C/C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/vector"
	cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
	echo "Done!"
}