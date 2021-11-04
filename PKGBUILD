pkgname="sstring"
pkgver="45.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=(
  "e069ed31d79f2ea0c5be14954c3d4eced6443b1663c0d53697fdbcce3011f71c3627a12fc5491dde76ab1360532785a5e26530a2ee036bb3aeb37951a5af395e"
  "6eb83e318d647cc8ea19434495fb438d0316d73485b0622d48ec058ee5b69838d4c5a34afd27f2b2f6978199551c6fbdb15bf407120cd9256819c0eabbe96d6b"
  "cc08a608c31f7ec514a1e214ab67ca3e2066aaaca7de24afee7cb9400756e9aa9f7c93568cb8b49e7d5b22f64212b1960455d833cf14cc2a4d1234fa60322a96"
  "5024ecbecc59e8100d3755bd788979ec86dd73aee206a22b6897a363998dae2133673e66010b6db8b2dc24727a9bcd60bb721ecbc07a0caaa04fc6ac90a89673")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
